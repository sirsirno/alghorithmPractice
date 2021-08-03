using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace algorithm_summer_15
{
    class Program
    {
        static string ContinuosStr(int length)
        {
            string str = "";

            for (int i = 3; i < length + 3; i++)
            {
                str = i % 2 == 0 ? str += "슉" : str += "슈";
            }

            return str;
        }
        static void Main(string[] args)
        {
            int count = int.Parse(ReadLine());

            if ( count < 1 )
            {
                Write("길이는 0이상이어야 합니다 ^^");

                return;
            }

            foreach (var item in ContinuosStr(count))
            {
                Write(item);
            }
        }
    }
}
