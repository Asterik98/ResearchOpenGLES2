precision mediump float;
uniform vec4 lightColor;
uniform vec4 objectColor;
varying vec2 v_uv;
void main() {  
	float ambientStrength=0.1;
	vec4 ambient = ambientStrength*lightColor;
	gl_FragColor = vec4(ambient*objectColor); 
} 
