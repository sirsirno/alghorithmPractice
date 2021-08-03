using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace algorithm_summer_05
{
    class Program
    {

        static int[] DeleteMinValueInArr(int[] arr)
        {
            int minValue = 0;
            List<int> list = arr.ToList();

            int saveCount = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                if (i == 0) minValue = arr[i];

                if (minValue > arr[i])
                {
                    minValue = arr[i];

                    saveCount = i;
                }
            }
            if(list.Count == 1)
            {
                list[0] = -1;
            }
            else
            {
                list.RemoveAt(saveCount);
            }
            
            arr = list.ToArray();



            return arr;
        }
        static void Main(string[] args)
        {
            Random ran = new Random();
            int arrCount = int.Parse(ReadLine());
            if (arrCount < 1)
            {
                WriteLine(" 배열 카운트는 길이 1 이상이 필수불가결 합니다");
                return;
            }
            int[] iArr = new int[arrCount];

            for (int i = 0; i < iArr.Length; i++)
            {
                iArr[i] = ran.Next(1, 7999999);
            }



            WriteLine("배열 요소 제거 전");
            foreach (var item in iArr)
            {
                WriteLine(item);
            }
            WriteLine("베열 요소 함수 사용 후");
            foreach (var item in DeleteMinValueInArr(iArr))
            {

                WriteLine(item);
            }
            


        }
    }
}
