<?php
$binary = new Binary();
$src = (int)rtrim(fgets(STDIN));
$result = array(
    "0" => 0,
    "1" => 0,
    "reverse" => array(),
    "2sComplement" => $binary->complement($src)
);
foreach(str_split($result["2sComplement"]) as $item) {
    if ($item == "0" || $item == "1") {
        $result[$item] += 1;
    }
}
$result["reverse"]["2sComplement"] = join("", array_reverse(str_split($result["2sComplement"])));
$result["reverse"]["dec"] = $binary->complement2dec($result["reverse"]["2sComplement"]);
fwrite(STDOUT,
    $result["2sComplement"] .
    "\nZeros: " . $result["0"] .
    "\nOnes: " . $result["1"] .
    "\n" . $result["reverse"]["2sComplement"] .
    "\n" . $result["reverse"]["dec"] .
    "\n"
);

function toFixed($num = "", $length = 32, $symbol = 0) {
    $num = "" . $num; // toString
    if (strlen($num) < $length) {
        return $symbol . str_repeat("0", $length - 1 - strlen($num)) . $num;
    }
    return $num;
}

// "abs" method in php2c engine has issue, have to overwrite that
function to_abs($num) {
    $num .= "";
    return (int)join(array_filter(str_split($num), function($el) {
        return $el != "-";
    }));
}

class Binary {
    protected $length;
    public function __construct($length = 32) {
        $this->length = $length;
    }
    public function getBinary($num) {
        return decbin(to_abs($num));
    }
    // 原码
    public function trueForm($num) {
        $two = $this->getBinary($num);
        if ($num >= 0) {
            return toFixed($two, $this->length, 0);
        }
        return toFixed($two, $this->length, 1);
    }
    // 反码
    public function inverse($num) {
        $trueForm = $this->trueForm($num);
        if ((int)$num >= 0) {
            return $trueForm;
        }
        $data = '';
        foreach(str_split($trueForm) as $k => $item) {
            if ($k == 0) {
                $data .= $item;
            }else {
                $data .= to_abs(+$item - 1);
            }
        }
        return $data;
    }
    // 补码
    public function complement($d) {
        $trueForm = $this->trueForm($d);
        $inverse = $this->inverse($d);
        if ($d >= 0) {
            return $trueForm;
        }
        $valid = substr($inverse, 1);
        $validTenComplete = bindec('' . $valid) + 1;
//        echo "valid: $valid\nvalidTenComplete: $validTenComplete\n\n";
        return toFixed(decbin($validTenComplete), $this->length, 1);
    }
    // 2's complement to dec
    public function complement2dec($num) {
        $stack = array();
        $is_negative = (int)substr($num, 0, 1) == 1;
        $find_first_0 = false;
        foreach(array_reverse(str_split($num)) as $item) {
            $item = (int)$item;
            if ($find_first_0) {
                array_push($stack, to_abs($item - 1));
            }else {
                array_push($stack, $item);
                if ($item == 1) {
                    $find_first_0 = true;
                }
            }
        }
        return ($is_negative ? "-" : "") . bindec(join('', array_reverse($stack)));
    }
}
/*
11111111111111111111111110011101
Zeros: 3
Ones: 29
10111001111111111111111111111111
-1174405121
*/
