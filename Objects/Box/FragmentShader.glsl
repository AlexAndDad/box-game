#version 330 core
out vec4 FragColor;


//in vec3 ourColor;
in vec2 TexCoord;
in vec3 NormalVec;
in vec3 FragPos;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform vec3 lightPos;



void main()
{
    vec3 lightPos = vec3(1.0,0.0,1.0);
    vec3 lightColor = vec3(1.0,1.0,1.0);

    float ambientStrength = 0.01;
    vec3 ambient = ambientStrength * lightColor;

    vec3 norm = normalize(NormalVec);
    vec3 lightDir = normalize(lightPos-FragPos);

    float diff = max(dot(norm,lightDir),0.0);
    vec3 diffuse = diff * lightColor;


    vec3 result = (ambient + diffuse) * vec3(texture(texture1,TexCoord)) ;
    FragColor = vec4(result,1.0);

}