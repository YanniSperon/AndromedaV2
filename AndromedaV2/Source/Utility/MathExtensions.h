#pragma once

// TODO

class Math {

	template <class T>
	static T Round(const T& input) {
		return T + 0.5;
	}

	template <class T>
	static T Map(const T& input, const T& inputRangeStart, const T& inputRangeEnd, const T& outputRangeStart, const T& outputRangeEnd) {
		return outputRangeStart + ((outputRangeEnd - outputRangeStart) / (inputRangeEnd - inputRangeStart)) * (input - inputRangeStart);
	}

	template<>
	static int Map(const int& input, const int& inputRangeStart, const int& inputRangeEnd, const int& outputRangeStart, const int& outputRangeEnd) {
		return outputRangeStart + Math::Round(((static_cast<double>(outputRangeEnd) - static_cast<double>(outputRangeStart)) / (static_cast<double>(inputRangeEnd) - static_cast<double>(inputRangeStart))) * (static_cast<double>(input) - static_cast<double>(inputRangeStart)));
	}

	template <class T>
	static T Lerp(const double& time, const T& startValue, const T& endValue) {
		return startValue * (1.0 - time) + endValue * time;
	}

	template<>
	static int Lerp(const double& time, const int& startValue, const int& endValue) {
		return static_cast<double>(startValue) * (1.0 - time) + static_cast<double>(endValue) * time;
	}
};
