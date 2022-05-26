#pragma once
#include "OpenGLFramework.h"
#include "OpenGLFrameworkExtensions/Animation/Vec4Interpolation.h"

class HapticShape {
	Vec4Interpolation shapeNormalised;
	float _length;
	char _name[64];
public: 	
	HapticShape(char* name, std::vector<glm::vec4> positions, std::vector<float> time_0_1) : shapeNormalised(0, 1, glm::vec4(0, 0, 0, 1), glm::vec4(0, 0, 0, 1)), _length(0)
	{
		strcpy(this->_name, name); 

		init(positions, time_0_1);
	}

	HapticShape(char* name, std::vector<glm::vec4> positions) :shapeNormalised(0, 1, glm::vec4 (0,0,0,1), glm::vec4(0, 0, 0, 1)), _length(0) {
		strcpy(this->_name, name);
		//Build time by homogeneously distributing points between 0 and 1s. 
		std::vector<float> times;
		for (int index = 0; index < positions.size(); index++)
			times.push_back(index*1.0f / positions.size());
		init(positions, times);
	}

	float length() { return _length; }

	char* name() { return _name; }

	/*Discretises the shape into a number of samples (which will determine the speed at which it renders, frequencye, etc)
	*/
	float* discretiseShape(int numSamples) {
		//1. Render shape
		float samplingRate = 1.0f / numSamples; 
		size_t bufferSize = numSamples*4;
		float* buffer = new float[bufferSize];
		float* b_pointer = buffer;
		for (int s = 0; s < numSamples; s++) {
			float t = s * samplingRate;
			//Compute the time. The shape is defined over a "virtual" period of time of 1 unit (i.e. t in [0..1))
			samplePoint(b_pointer, t);
			b_pointer += 4; 			
		}
		return buffer;
	}

private: 
	void init(std::vector<glm::vec4> positions, std::vector<float> time_0_1) {
		shapeNormalised = Vec4Interpolation(time_0_1[0], time_0_1[1], positions[0], positions[1]);
		//Add each remaining points defining the shape
		for (int index = 2; index < positions.size(); index++)
			shapeNormalised.addNextStage(time_0_1[index], positions[index]);
		//Cpnnect back to the starting point (shapes must be closed).
		shapeNormalised.addNextStage(1.0f, positions[0]);
		//Compute total length:
		for (int i = 0; i < positions.size(); i++) {
			if (i < positions.size() - 1) _length += glm::distance(positions[i], positions[i + 1]);
			else _length += glm::distance(positions[i], positions[0]);
		}
	}
	
	void samplePoint(float* positionXYZW, float timeNormalised) {
		//0. Get decimal part of time
		float aux = 1;
		float time_0_1 = modf(timeNormalised, &aux);
		//2. Get the 3d point
		shapeNormalised.interpolate(time_0_1);
		glm::vec4 curPos=shapeNormalised.getCurrentVec4();
		//3. Store it
		memcpy(positionXYZW, &curPos, 4 * sizeof(float));
		//4. Interpolations are optimised to be accessed sequentially (e.g. as time progresses through an animation). We might sample it at random, so we better restore afterwards...
		shapeNormalised.restart(0);
	}
};