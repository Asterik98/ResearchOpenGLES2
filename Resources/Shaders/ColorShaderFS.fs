precision mediump float;
uniform vec4 lightColor;
uniform vec4 objectColor;
varying vec2 v_uv;

void main() {  

	gl_FragColor = vec4(vec4(1.0, 1.0, 1.0,1.0)*vec4(1.0, 0.5, 0.31,1.0)); 
} 
