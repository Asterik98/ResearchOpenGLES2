precision mediump float;
uniform vec3 lightColor;
uniform vec3 objectColor;
uniform vec3 lightPos;
varying vec3 Normal;
varying vec3 FragPos;
void main() {  
	float ambientStrength=0.3;
	vec3 ambient = ambientStrength*lightColor*objectColor;

	vec3 norm= normalize(Normal);
	vec3 lightDir = normalize((lightPos)-FragPos);
	float diff= max(dot(norm,lightDir),0.0);
	vec3 diffuse= diff * lightColor;

	vec3 result = (ambient+diffuse)*objectColor;
	gl_FragColor = vec4(result,1.0); 
} 
