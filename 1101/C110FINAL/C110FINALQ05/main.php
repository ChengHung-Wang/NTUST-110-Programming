<?php
$limit = (int)rtrim(fgets(STDIN));
$input = array();
$config = array(
    "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"
);
$abc = join("", $config);
$config = array_map(function($el) {
    return str_split($el);
}, $config);
for($i = 0; $i < $limit; $i ++) {
    array_push($input, str_split(rtrim(fgets(STDIN))));
}
foreach ($input as $data) {
    $charLimit = 0;
    $dashLimit = 0;
    foreach ($data as $item) {
        if (in_array($item, str_split($abc))){
            foreach ($config as $k => $v) {
                if (in_array($item, $v)) {
                    echo $k + 2;
                    $charLimit ++;
                }
            }
        }else {
            if ($item == "1" || $item == "0" || $item == "-") {
                echo $item;
                if ($item == "-") {
                    $dashLimit ++;
                }
            }
        }
    }
    echo " " . $charLimit . " " . $dashLimit;
    echo "\n";
}
/*
2
1-HOME-SWEET-HOME
MY-MISERABLE-JOB
*/