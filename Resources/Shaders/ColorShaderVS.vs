attribute vec3 a_posL;
attribute vec3 a_norm;
varying vec3 Normal;
varying vec3 FragPos;
uniform mat4 u_worldMatrix;
uniform mat4 u_model;
uniform mat3 u_invModel;
uniform vec3 lightColor;
uniform vec3 objectColor;
void main() {            
	FragPos = vec3(u_model*vec4(a_posL,1.0));
	Normal= u_invModel * a_norm;
	gl_Position= u_worldMatrix*vec4(FragPos,1.0);
} 
