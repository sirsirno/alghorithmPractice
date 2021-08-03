using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

// 8번 문제 

namespace algorithm_summer_08
{
    class Program
    {

        static int CollazBenedict(int num)
        {
            int totalCount = 0;

            while(num != 1)
            {
                if(totalCount ==500)
                {
                    return -1;
                }

                num = (num % 2 == 0) ? (num / 2) : (num * 3 + 1);

                Write(num + " -> ");

                totalCount++;
            }
          

            

            return totalCount;
        }
        static void Main(string[] args)
        {
            int input = int.Parse(ReadLine());

            if (input < 0)
            {
                WriteLine("음수이기 때문에 양수로 보간 시켜드림");

                input *= -1;
            }

            WriteLine(CollazBenedict(input));
            
        }
    }
}
