precision mediump float;
uniform vec3 lightColor;
uniform vec3 objectColor;
varying vec2 v_uv;

void main() {  
	gl_FragColor = vec4(lightColor*objectColor,1.0); 
} 
