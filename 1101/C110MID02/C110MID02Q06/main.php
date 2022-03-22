<?php
$limit = rtrim(fgets(STDIN));
$data = array();
rtrim(fgets(STDIN));
for ($i = 0; $i < $limit; $i++) {
    $enable = true;
    $cache = array();
    while ($input = rtrim(fgets(STDIN))) {
        array_push($cache, $input);
    }
    array_push($data, $cache);
}
// L means Layer
// L0 => all data
// L1 => one item form $data
// L2 => each line
// L3 => each split by " " word group
$L0_stack = [];
foreach ($data as $L1_index => $L1) {
    $result =  "Case #" . $L1_index . ":\n";;
    foreach ($L1 as $L2) {
        $index = 0;
        $stack = array();
        foreach (explode(" ", $L2) as $L3) {
            $L3 = str_split(rtrim($L3));
            if (isset($L3[$index])) {
                array_push($stack, $L3[$index]);
                $index++;
            }
        }
        $result = $result . join("", $stack) . "\n";
    }
    array_push($L0_stack, $result);
}
echo join("\n", $L0_stack);

//var_dump($data);


/*
Hey good lawyer
as I previously previewed
yam does a soup

First I give money to Teresa
after I inform dad of
your horrible soup
*/