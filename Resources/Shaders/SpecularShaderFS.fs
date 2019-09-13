precision mediump float;
uniform vec3 lightColor;
uniform vec3 objectColor;
uniform vec3 lightPos;
uniform vec3 viewPos;
varying vec3 Normal;
varying vec3 FragPos;
void main() {  

	vec3 norm= normalize(Normal);
	vec3 lightDir = normalize(lightPos-FragPos);
    float specularStrength = 0.9;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 3.0);
    vec3 specular = specularStrength * spec * lightColor; 

	vec3 result = (specular) * objectColor;
	gl_FragColor = vec4(result,1.0); 
} 
