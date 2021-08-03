using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

// 7번 문제 
namespace algorithm_summer_07
{
    class Program
    {

        static List<int> MakeDistanceList(int intNum , int naturalNum)
        {
            List<int> list = new List<int>();
            int count = intNum;

            for (int i = 0; i < naturalNum -1 ; i++)
            {
                if (i == 0) list.Add(intNum);

                count += intNum;
                list.Add(count);
                

            }

            return list;
        }
        static void Main(string[] args)
        {
            int iNum = int.Parse(ReadLine());
            int nNum = int.Parse(ReadLine());

            if(iNum > 10000000 || iNum < -10000000 ||
                nNum < 1 || nNum > 1000)
            {
                WriteLine($"{iNum}은 -10000000 이상 10000000 이하인 정수이어야합니다.");
                WriteLine($"{nNum}은  1000 이하인 자연수이어야합니다.");
                return;
            }

            foreach (var item in MakeDistanceList(iNum, nNum))
            {
                WriteLine(item);
            }
        }
    }
}
