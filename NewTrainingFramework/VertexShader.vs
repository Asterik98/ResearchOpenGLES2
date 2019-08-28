attribute vec2 a_uv; 
attribute vec3 a_posL;
attribute vec3 a_VColor;
varying vec3 a_FColor;
varying vec2 v_uv;
uniform vec3 u_pos;
uniform vec3 u_sca;
uniform mat4 u_worldMatrix;
void main() {            
	vec4 posL = vec4(a_posL, 1);
	posL= u_worldMatrix * posL;
	gl_Position = posL;
	a_FColor=a_VColor;
	v_uv = a_uv; 
} 
