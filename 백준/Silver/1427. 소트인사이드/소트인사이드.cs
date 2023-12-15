using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        string input = Console.ReadLine(); // 문자열 형태로 숫자를 입력받음
        
        List<int> number = input.Select(c => int.Parse(c.ToString())).ToList(); // 각 문자를 정수로 변환하여 리스트에 추가

        number.Sort((a, b) => b.CompareTo(a));

        for(int i = 0; i < number.Count; i++)
        {
            Console.Write($"{number[i]}");
        }
    }
}