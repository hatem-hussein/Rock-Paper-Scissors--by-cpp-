#pragma once

#include <iostream>

using namespace std;

namespace RandLib
{
	
	int RandomNumber_From_To(int from, int to)
	{
		return rand() % (to - from + 1) + from;
	}


}