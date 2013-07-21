nclude <iostream>
#include <vector>
#include <algorithm>

#define INTARRAYLEN(a) ((sizeof(a))/(sizeof(int)))

using namespace std;

class ZigZag{
public:
     int longestZigZag(vector<int> sequence)
     {

          if(sequence.size() == 1) return 1;
          int len = sequence.size();
          int* maxLen = new int[len*2];
          for(int i = 0; i < 2*len; i++)
          {
               maxLen[i] = 1;
          }
          for( int i = 0; i < len; i++)
          {
               for(int j = 0; j < i; j++)
               {
                    if(sequence[i] > sequence[j])
                    {
                         if((maxLen[2*j+1] + 1 ) > maxLen[2*i])
                              maxLen[2*i] = maxLen[2*j+1]+1;
                    }
                    else if(sequence[i] < sequence[j])
                    {
                         if((maxLen[2*j] + 1) >maxLen[2*i+1])
                              maxLen[2*i+1] = maxLen[2*j]+1;
                    }
               }
          }
          int maxNum = 1;
          for(int i = 0; i < 2*len; i++)
          {
               if (maxLen[i] > maxNum)
                    maxNum = maxLen[i];
          }
          delete[] maxLen;
          return maxNum;
     }
};

int main()
{
     int seq[] = {12, 333, 700, 436, 1, 919, 959, 456, 456, 456, 1000, 193, 192, 13, 75, 818, 197, 197, 2, 777, 99, 81, 222, 109, 1000, 19, 27, 270, 62, 189, 987, 234, 55, 2, 718, 238, 901, 901, 900, 432, 55, 606, 89, 7, 7, 23, 789, 790, 800, 1000};
     vector<int> sequence(seq, seq + INTARRAYLEN(seq));
     ZigZag op;
     int maxPath = op.longestZigZag(sequence);
     cout<<maxPath<<endl;

     return 0;
}
