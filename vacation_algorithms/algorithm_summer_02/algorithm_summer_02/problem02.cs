using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace algorithm_summer_02
{
    class Program
    {
        string JudgeNum(int num)
        {
            string str;
            num = num % 2;

            switch (num)
            {

                case 0:
                    str = "Even";
                    break;
                case 1:
                    str = "Odd";
                    break;
                default:
                    str = "Error";
                    break;
            }
            return str;
        }
        void Main(string[] args)
        {
            int num = int.Parse(ReadLine());



            WriteLine(JudgeNum(num));

        }

        
    }
}
