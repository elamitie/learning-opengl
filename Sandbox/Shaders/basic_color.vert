#version 130

in vec2 vertexPos;
in vec4 vertexColor;
in vec2 vertexUV;

out vec2 fragPosition;
out vec4 fragColor;
out vec2 fragUV;

uniform mat4 projectionMatrix;

void main()
{
	gl_Position.xy = (projectionMatrix * vec4(vertexPos, 0.0, 1.0)).xy;
	gl_Position.z = 0.0;
	gl_Position.w = 1.0;
	
	fragPosition = vertexPos;
	fragColor = vertexColor;
	fragUV = vec2(vertexUV.x, 1.0 - vertexUV.y);
}