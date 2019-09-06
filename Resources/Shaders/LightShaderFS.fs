precision mediump float;        // Set the default precision to medium. We don't need as high of a
                                // precision in the fragment shader.
uniform vec3 u_LightPos;        // The position of the light in eye space.
uniform sampler2D u_Texture;    // The input texture.
 
varying vec3 v_pos;        // Interpolated position for this fragment.
varying vec4 a_FColor;           // This is the color from the vertex shader interpolated across the
                                // triangle per fragment.
varying vec3 v_Normal;          // Interpolated normal for this fragment.
varying vec2 v_uv;   // Interpolated texture coordinate per fragment.
 
void main()
{

    float distance = length(u_LightPos - v_pos);
 
    vec3 lightVector = normalize(u_LightPos - v_pos);

    float diffuse = max(dot(v_Normal, lightVector), 0.0);
 
    // Add attenuation.
    diffuse = diffuse * (1.0 / (1.0 + (0.10 * distance)));
 
    // Add ambient lighting
    diffuse = diffuse + 0.3;
 
    // Multiply the color by the diffuse illumination level and texture value to get final output color.
    gl_FragColor = (a_FColor * diffuse * texture2D(u_Texture, v_uv));
  }