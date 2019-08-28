attribute vec3 a_posL;
attribute vec3 a_VColor;
varying vec3 a_FColor;
uniform vec3 u_pos;
uniform vec3 u_sca;
void main()
{
	vec4 posL =(vec4(a_posL, 1.0)+vec4(u_pos,0.0))*vec4(u_sca,1.0);
	gl_Position = posL;
	a_FColor=a_VColor;
}
   