<?php
// pacman
$data = array();
$logs = array();
$wall = "#";
$walked_taken = "R";
$can_walk_taken = "X";
$last_side = "right";
$pacman_side = array(
    //         array(y, x)
    "right" => array(0, 1),
    "top"   => array(-1, 0),
    "left"  => array(0, -1),
    "down"  => array(1, 0)
);

// ask data
for($i = 0; $i < 12; $i ++) {
    array_push($data, str_split(rtrim(fgets(STDIN))));
}
if (
    !in_array($can_walk_taken, array_map(function ($el) {return $el[0];}, $data)) ||
    !in_array($can_walk_taken, array_map(function ($el) {return end($el);}, $data))
) {
    echo "This maze has no solution\n";
    return;
}else {
    foreach($data as $index => $row) {
        if ($row[0] == $can_walk_taken) {
            array_push($logs, log_map($index, 0, "right"));
            if (! walk()) {
                echo "This maze has no solution\n";
            }

            break;
        }
    }
}

function walk() {
    global $data,
           $logs,
           $last_side,
           $pacman_side,
           $walked_taken,
           $can_walk_taken;


    return true;
}

function log_map($row, $col, $type) {
    return array(
        "x" => $col,
        "y" => $row,
        "side" => $type
    );
}



/*
############
##XXXXX#XXX#
##X###X###X#
##X#XXXXXXX#
##X#######X#
#XX#X####XX#
XX##XXXXXX##
####X##X##X#
#X#X#XXX##X#
#X#X##X#XXX#
#XXX##XXX#XX
############
 */