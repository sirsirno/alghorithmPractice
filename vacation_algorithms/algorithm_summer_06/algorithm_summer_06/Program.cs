using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

// 6번 문제 

namespace algorithm_summer_06
{
    class Program
    {
        static int[] GreatestLeastCommonValue(int value1, int value2)
        {
            int num1 = value1;
            int num2 = value2;
            int greatestResult = 0;
            int leastResult = 0;
            while (num2 != 0)  // 최대공약수를 구하는 법 중 하나인 유클리드 호제법을 가져와서 이용함.
            {
                int temp = num2;
                num2 /= num1;              
                num1 = temp;

                greatestResult = num1;

            }
           
            leastResult = (value1 * value2) / greatestResult; // 최소공배수 역시 유클리드 호제법을 이용하였음.

            value1 = greatestResult;
            value2 = leastResult;

            int[] iArr = new int[2] { value1, value2 };


            return iArr;
        }
        static void Main(string[] args)
        {
            int value01 = int.Parse(ReadLine());
            int value02 = int.Parse(ReadLine());
            int temp = 0;

            if( value01 > 10000000 || value01 < 1 || 
                value02 > 10000000 || value02 < 1 ||
                value01 == value02)
            {
                WriteLine(" 예기치않은 수 할당이 존재합니다 ");
                return;
            }
            if(value01 < value02)
            {
                temp = value01;
                value01 = value02;
                value02 = temp;
               
            }

            foreach (var item in GreatestLeastCommonValue(value01,value02))
            {
                WriteLine(item);
            }

        }
    }
}
