namespace 스타트와_링크
{
    internal class AtticYellow
    {
        static int N;
        static int[,] S;
        static bool[] visited;
        static int minDiff = int.MaxValue;

        static void Main()
        {
            N = int.Parse(Console.ReadLine());
            S = new int[N, N];
            visited = new bool[N];

            for (int i = 0; i < N; i++)
            {
                string[] input = Console.ReadLine().Split();
                for (int j = 0; j < N; j++)
                {
                    S[i, j] = int.Parse(input[j]);
                }
            }

            DFS(0, 0);
            Console.WriteLine(minDiff);
        }

        static void DFS(int depth, int idx)
        {
            if (depth == N / 2)
            {
                CalculateTeamAbility();
                return;
            }

            for (int i = idx; i < N; i++)
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    DFS(depth + 1, i + 1);
                    visited[i] = false;
                }
            }
        }

        static void CalculateTeamAbility()
        {
            int startTeam = 0;
            int linkTeam = 0;

            for (int i = 0; i < N - 1; i++)
            {
                for (int j = i + 1; j < N; j++)
                {
                    if (visited[i] && visited[j])
                    {
                        startTeam += S[i, j] + S[j, i];
                    }
                    else if (!visited[i] && !visited[j])
                    {
                        linkTeam += S[i, j] + S[j, i];
                    }
                }
            }

            int diff = Math.Abs(startTeam - linkTeam);
            if (diff == 0)
            {
                Console.WriteLine(0);
                Environment.Exit(0);
            }

            minDiff = Math.Min(minDiff, diff);
        }
    }
}
