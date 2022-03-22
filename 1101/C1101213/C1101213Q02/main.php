<?php
$data = array();
$limit = (int)rtrim(fgets(STDIN));
for($i = 0; $i < $limit; $i ++) {
    array_push($data, rtrim(fgets(STDIN)));
}
foreach ($data as $index => $item) {
    echo "Case " . ($index + 1) . ": ";
    $english_stack = array();
    $limit_stack = array();
    foreach (str_split($item) as $char_index => $el) {
        if (is_numeric($el)) {
            if (is_numeric(str_split($item)[$char_index - 1])) {
                $limit_stack[count($limit_stack) - 1] = $limit_stack[count($limit_stack) - 1] . $el;
            }else {
                array_push($limit_stack, $el);
            }
        }else {
            array_push($english_stack, $el);
        }
    }
    foreach($english_stack as $index => $value) {
        echo str_repeat($value, $limit_stack[$index]);
    }
    echo "\n";
}




/*
3
A2B4D1A2
A12
A1B1C1D1
*/