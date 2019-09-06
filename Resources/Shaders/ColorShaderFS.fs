precision mediump float;
uniform vec4 lightColor;
uniform vec4 objectColor;
varying vec2 v_uv;

void main() {  
	gl_FragColor = vec4(lightColor*objectColor); 
} 
