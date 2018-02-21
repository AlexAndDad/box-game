#Introduction

An OpenGL render environment involves a number of concepts. These are:

## Display

The display is the "screen" on which we are rendering. An OpenGL driver will consider that a screen maps 1:1 to a graphics card.

## Context

This is the OpenGL rendering context. When a GLFW window is created, it generates a Context which is tied to the current Display (the one the window is on).

## Context-Specific settings

These are things like Projection matricies, display lists and (I think) VAOs.

## Display or Graphics Card - specific resources

As I understand it, all shader programs and textures are stored "per display", not "per context"

#Design

This leads me to think about graphics resource management in the following way:

## DisplayContext

An object that represents the underlying display. This will manage the loading, unloading and availabilit of resources such as textures

## RenderContext 

An object that manages the per-context settings. It would keep a reference to its DisplayContext. Requests to the RenderContext for a resource would be deferred to the DisplayContext.

The RenderContext might be tied to the GLFW window object in some way. I am not sure yet which one should own the other. Probably the GlFW window is subcomponent of the RenderContext.

## DrawService

Every controller (e.g. BoxController) needs a Service to manage the resources shared by all similar objects. 
It would make sense therefore for there to be a tight relationship between the DrawService and the RenderContext, since 
DrawServices will need to know about resources and settings in the RenderContext (and its associated DisplayContext), 
but equally the RenderContext may want to issue once-per-render-cycle commands to all known DrawService objects.

When a BoxView is being draw, it would request its BoxViewService from the RenderContext, which keeps a cache of such 
objects

The code to request could look like this:

```{c++}
void Draw(BoxData const& data, RenderContext& context)
{
    // returns a prepared service object
    // which has already initialised itself with the correct 
    // projection matrix, VAOs etc
    auto& service = context.useService<BoxViewService>();
    
    service.setPosition(data.position());
    service.setOrientation(dtaa.orientation());
    service.render();
}

```

The 'use' template method on the RenderService will require some explaining but something like this:

```{c++}

struct DrawService
{
    DrawService(RenderContext& owner);
    
    // causes missing resources to be loaded
    virtual void loadResources() = 0;
    
    // causes the object to prepare itself (e.g. use program)
    virtual void prepare() = 0;
}

// In the RenderContext object...
std::unordered_map<std::typeindex, std::unique_ptr<DrawService>> serviceCache_;

template<class ServiceModel>
auto use() -> ServiceModel&
{
    auto& candidate = serviceCache_[typeid(ServiceModel)];
    if (not candidate)
    {
        candidate = std::make_unique<ServiceModel>(*this);
        candidate->loadResources();
    }
    return static_cast<ServiceModel&>(*candidate);
}
```

In this case, 'ServiceModel' can be any class which has been derived from the polymorphic base class 'DrawService'

