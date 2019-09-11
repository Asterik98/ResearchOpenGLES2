attribute vec3 a_posL;
uniform mat4 u_worldMatrix;
uniform mat4 u_model;
void main() {            
	vec4 posL = vec4(a_posL, 1);
	gl_Position= u_worldMatrix *u_model* posL ;

} 
