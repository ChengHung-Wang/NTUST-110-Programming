<?php
$data = str_split(rtrim(fgets(STDIN)));
$max = max($data);
echo $data[0] . "\n";
foreach($data as $item) {
    for ($i = 2; $i <= $item; $i+= 2) {
        echo str_repeat(" ", (int)($max - $i + 1) / 2) . str_repeat($i, $i) . "\n";
    }
    for ($i = $item - 1; $i <= 1; $i --) {
        echo str_repeat($item, $i) . "\n";
    }
}


//int main()
//{
//int n;
//	scanf("%d", &n);
//
//	for (int line = 0; line < n; line++)
//	{
//        // whitespace
//        for (int i = 0; i < n - 1 - line; i++)
//		{
//            putchar(' ');
//        }
//
//		// character
//		for (int i = 0; i < line * 2 + 1; i++)
//		{
//            printf("%d", line);
//        }
//
//		putchar('\n');
//	}
//}