<?php
	$data = array();
	$boomConfig = array("*");
	$position = array(
        // [x, y]
        array(0, 1), // up
		array(0, -1), // down
		array(1, 1), // bottom right
		array(1, -1), // top right
		array(1, 0), // right
		array(-1, 0), // left
        array(-1, 1), // bottom left
        array(-1, -1) // top left
    );

    askData();
    foreach($data as $index => $item) {
        printResult(scan($item, $boomConfig, $position), "Field #%d:\n", (int)($index + 1));
    }

	function askData() {
	    global $data;
        $input = explode(" ", rtrim(fgets(STDIN)));
        $row = (int)$input[0];
        $col = (int)$input[1];
	    while($row != 0 && $col != 0) {
	        $cache = array(
	            "row" => (int)$row,
                "col" => (int)$col,
                "data" => array()
            );
	        for ($i = 0; $i < $row; $i ++) {
	            array_push($cache["data"], str_split(rtrim(fgets(STDIN))));
            }
            array_push($data, $cache);
            $input = explode(" ", rtrim(fgets(STDIN)));
            $row = (int)$input[0];
            $col = (int)$input[1];
        }
    }

    function scan($area, $boom = array(), $tryPosition) {
	    $result = array();
	    foreach($area["data"] as $rowIndex => $row) {
	        $cache = "";
	        foreach($row as $colIndex => $col) {
	            if (in_array($col, $boom)) {
	                $cache .= $col;
                }else {
                    $limit = 0;
                    foreach ($tryPosition as $position) {
                        $x = $colIndex + $position[0];
                        $y = $rowIndex + $position[1];
                        if (!isset($area["data"][$y][$x])) continue;
                        $thisEl = $area["data"][$y][$x];
                        if (in_array($thisEl, $boom)) {
                            $limit += 1;
                        }
                    }
                    $cache .= $limit;
                }
            }
	        array_push($result, $cache);
        }
	    return $result;
    }

    function printResult($data, $format, $index) {
        echo sprintf($format, $index);
        foreach($data as $item) {
            echo sprintf("%s\n", $item);
        }
        echo "\n";
    }