precision mediump float;
uniform vec3 lightColor;
uniform vec3 objectColor;
void main() {  
	float ambientStrength=0.2;
	vec3 ambient = ambientStrength*lightColor;
	vec3 result=ambient*objectColor;
	gl_FragColor = vec4(result,1.0); 
} 
