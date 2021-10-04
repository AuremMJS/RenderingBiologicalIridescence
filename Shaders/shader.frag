#version 450
#extension GL_ARB_separate_shader_objects : enable

// Texture sampler uniform
layout(binding = 2) uniform sampler2D texSampler;

layout(binding = 7) uniform sampler2D normalSampler;

// Uniform for Iridescent colours
layout(binding = 6) uniform IridescentColors {
    vec4 colors[90];
} iridescentColors;

// Input values to the fragment
layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec2 fragTexCoord;
layout(location = 2) in vec4 fragLightVector;
layout(location = 3) in vec4 fragEyeVector;
layout(location = 4) in vec3 fragSpecularLighting;
layout(location = 5) in vec3 fragDiffuseLighting;
layout(location = 6) in vec3 fragAmbientLighting;
layout(location = 7) in float fragSpecularCoefficient;
layout(location = 8) in vec3 fragNormal;
layout(location = 9) in vec4 stagesInfo;
layout(location = 10) in float fragSpecularIntensity;
layout(location = 11) in float fragDiffuseIntensity;
layout(location = 12) in float fragAmbientIntensity;
layout(location = 13) in float transparency;
layout(location = 14) in float useNormalMap;
layout(location = 15) in float useOpacityMap;

// Output color of the fragment
layout(location = 0) out vec4 outColor;

void main() {
	
	// Calculate ambient component
	vec4 ambientLight = vec4(0);
	if(stagesInfo.x > 0.5)
		ambientLight = vec4(fragAmbientLighting * fragColor,1.0) *  fragAmbientIntensity;

	// Normalize the vectors
	vec4 normEyeVector = normalize(fragEyeVector);
	vec4 normLightVector = normalize(fragLightVector);
	vec4 normNormal = normalize(vec4(fragNormal,1.0));
	if(useNormalMap > 0.5)
		normNormal = normalize(texture(normalSampler, fragTexCoord));

	// Calculate the diffuse component
	float diffuseDotProduct = dot(normLightVector, normNormal);

	// Calculate the specular component
	vec4 halfAngleVector = normalize((normEyeVector + normLightVector)/2.0);
	float specularDotProduct = dot(halfAngleVector, normNormal);
	float specularPower = pow(max(0.0f,specularDotProduct), fragSpecularCoefficient);

	// Calculate the total lighting
	vec4 lightingColor = ambientLight;

	// Calculate the opacity from opacity map
	vec4 opacityColor = texture(texSampler, fragTexCoord);
	float opacity = opacityColor.x;

	// Calculate the angle of incidence
	int angle = 90 - int(ceil(diffuseDotProduct*90));

	// Fetch the iridescent colour
	vec4 iridescentColor = vec4(0.0);
	if(stagesInfo.y > 0.5 && stagesInfo.z >0.5)
		iridescentColor = iridescentColors.colors[angle]* fragSpecularIntensity * specularPower;
	else if(stagesInfo.y > 0.5 && stagesInfo.z <0.5)
		iridescentColor = iridescentColors.colors[angle]* fragSpecularIntensity;

	// Calculate the total colour
	lightingColor =  iridescentColor + ambientLight;

	// Render the iridescent colour or black based on opacity value
	if(opacity < 0.5 && useOpacityMap>0.5)
		lightingColor = vec4(0.0);
	outColor =min(vec4(lightingColor.xyz,transparency),vec4(1.0));
}