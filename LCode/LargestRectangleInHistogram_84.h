#pragma once
#include "solutions.h"
/*
	84. Largest Rectangle in Histogram
    Input [2,1,5,6,2,3]     output: 10
    感觉这道题似曾相识
    相似题目：最长上升字串？

    input:
        
    comments:
        
*/

class LargestRectangleInHistogram {
public:
    /*
        1. 暴力解法. 两个柱子间的高度 = 两个柱子间最低的柱子的高度 * 柱子距离
        这个算法也是网上看的... 
    */
    int LargestRectangleinHistogram(vector<int>& heights)
    {
        int largestRect = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            for (int j = i; j < heights.size(); j++)
            {
                // find the min height between i and j
                int minHeight = heights[i] < heights[j] ? heights[i] : heights[j];
                for (int k = i+1; k < j; k++)
                {
                    if (heights[k] < minHeight)
                        minHeight = heights[k];
                }
                int area = minHeight * (j - i + 1);
                largestRect = largestRect > area ? largestRect : area;
            }
        }
        return largestRect;
    }

    int LargestRectangleinHistogram_DivideConquer(vector<int>& heights)
    {
        return divideAndConquer(heights, 0, heights.size());
    }
private:
    size_t divideAndConquer(vector<int>& heights, size_t nstart, size_t end)
    {
  //      if (start == end)
  //          return heights[end];
  //      int minVal = UINT_MAX;
  //      size_t minIndex = start;
  //      for (size_t i = start; i < end; i++)
  //      {
  //          if (minVal > heights[i])
  //          {
  //              minVal = heights[i];
  //              minIndex = i;
  //          }
  //      }
  //      int maxLeft = divideAndConquer(heights, start, minIndex);
  //      int maxRight = divideAndConquer(heights, minIndex + 1, end);
		//int maxCurr = minVal * (end - start + 1);
  //      return max(max(maxCurr, maxLeft), maxRight);
    }
};
