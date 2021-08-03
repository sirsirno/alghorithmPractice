using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace algorithm_summer_01
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(ReadLine());
            int m = int.Parse(ReadLine());
            if (n > 1000 || m > 1000 || n < 0 || m < 0)
            {
                WriteLine(" n 또는 m 은 1000 이하의 자연수이어야 합니다.");
                return;
            }


            WriteLine($"가로 {n} , 세로 {m} 의 직사각형 넓이는 {n * m}");

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Write('*');
                }
                WriteLine();
            }


        }
    }
}
