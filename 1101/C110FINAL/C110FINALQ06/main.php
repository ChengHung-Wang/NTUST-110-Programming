<?php
$limit = (int)rtrim(fgets(STDIN));
$data = array();
$count = array();
for($i = 0; $i < $limit; $i ++) {
    array_push($data, rtrim(fgets(STDIN)));
}
foreach($data as $item) {
    $item = explode(" ", $item)[0];
    if (isset($count[$item])) {
        $count[$item] ++;
    }else {
        $count[$item] = 1;
    }
}
$keys = array_keys($count);
asort($keys);
foreach($keys as $main) {
    echo $main . " " . $count[$main] . "\n";
}