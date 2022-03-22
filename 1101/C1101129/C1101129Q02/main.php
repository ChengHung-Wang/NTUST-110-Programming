<?php
// BigNumber.php
final class BcMathNumber
{
    /**
     * Operations constants
     */
    private const OPERATION_ADD = 'add';
    private const OPERATION_SUB = 'sub';
    private const OPERATION_MUL = 'mul';
    private const OPERATION_DIV = 'div';
    private const OPERATION_POW = 'pow';
    private const OPERATION_MOD = 'mod';
    private const OPERATION_POWMOD = 'powmod';
    private const OPERATION_SQRT = 'sqrt';
    private const OPERATION_COMPARE = 'compare';

    private static $operationsMap = array(
        self::OPERATION_ADD => 'bcadd',
        self::OPERATION_SUB => 'bcsub',
        self::OPERATION_MUL => 'bcmul',
        self::OPERATION_DIV => 'bcdiv',
        self::OPERATION_POW => 'bcpow',
        self::OPERATION_MOD => 'bcmod',
        self::OPERATION_POWMOD => 'bcpowmod',
        self::OPERATION_SQRT => 'bcsqrt',
        self::OPERATION_COMPARE => 'bccomp'
    );

    /** @var int */
    private static $defaultScale = 8;

    /** @var string */
    private $value;

    /**
     * @param BcMathNumber|string $num
     */
    public function __construct($num = '0')
    {
        $this->value = $num instanceof self ? (string)$num : self::filterNum($num);
    }

    /**
     * @param BcMathNumber|string $num
     * @param int $scale
     * @return BcMathNumber
     */
    public function add($num, int $scale = null)
    {
        return self::create($this->performOperation(self::OPERATION_ADD, $num, null, $scale));
    }

    /**
     * @param BcMathNumber|string $num
     * @param int $scale
     * @return BcMathNumber
     */
    public function sub($num, int $scale = null)
    {
        return self::create($this->performOperation(self::OPERATION_SUB, $num, null, $scale));
    }

    /**
     * @param BcMathNumber|string $num
     * @param int $scale
     * @return BcMathNumber
     */
    public function mul($num, int $scale = null)
    {
        return self::create($this->performOperation(self::OPERATION_MUL, $num, null, $scale));
    }

    /**
     * @param BcMathNumber|string $num
     * @param int $scale
     * @return BcMathNumber
     */
    public function div($num, int $scale = null)
    {
        return self::create($this->performOperation(self::OPERATION_DIV, $num, null, $scale));
    }



    /**
     * @param BcMathNumber|string $num
     * @return BcMathNumber
     */
    public static function create($num)
    {
        return new self($num);
    }

    /**
     * @param BcMathNumber|null $num
     * @param int $scale
     * @return int
     */




    /**
     * @param string $operation
     * @param BcMathNumber|string $num
     * @param int $scale
     * @param BcMathNumber|string $mod
     * @return string
     */
    private function performOperation($operation, $num = null, $mod = null, int $scale = null)
    {
        $left = $this->getValue();
        $right = $num instanceof self ? $num->getValue() : self::filterNum($num);
        $mod = $mod instanceof self ? $num->getValue() : self::filterNum($mod);
        $scale = (int)(null === $scale ? self::$defaultScale : $scale);

        switch ($operation) {
            case self::OPERATION_POWMOD:
                $args = array($left, $right, $mod, $scale);
                break;
            case self::OPERATION_SQRT:
                $args = array($left, $scale);
                break;
            case self::OPERATION_MOD:
                $args = array($left, $right);
                break;
            default:
                $args = array($left, $right, $scale);
        }

        $func = self::$operationsMap[$operation];

        ob_start();
        $result = call_user_func_array($func, $args);
        $error = ob_get_flush();

        if ($error) {
            throw new BcMathException($error);
        }

        return $result;
    }

    /**
     * @return string
     */
    public function getValue()
    {
        return (string)$this;
    }

    /**
     * @return string
     */
    public function __toString()
    {
        return (string)$this->value;
    }


    /**
     * @param string $num
     * @return string
     */
    private static function filterNum($num)
    {
        $num = preg_replace(array('/,/', '/[^\-0-9E\.]/i'), array('.', ''), (string)$num);

        return self::convertFromScientificNotation($num);
    }

    /**
     * Converts a number from scientific notation if detected
     *
     * @param string $number
     * @return string
     */
    private static function convertFromScientificNotation(string $number)
    {
        if (!preg_match('/(.*?)E(-?\d+)$/i', $number, $matches)) {
            return $number;
        }

        $base = $matches[1];
        $exponent = $matches[2];

        $precision = explode('.', $base);
        $precision = (strlen($precision) + $exponent * -1);
        $precision = $precision >= 0 ? $precision : 0;

        return bcmul($base, bcpow(10, $exponent, abs($exponent)), $precision);
    }

}

$result = array();
$limit = (int)rtrim(fgets(STDIN));
for ($index = 0; $index < $limit; $index ++) {
    $compute_str = rtrim(fgets(STDIN));
    array_push($result, calc($compute_str));
}
echo join("\n", $result) . "\n";
function calc($str) {
    $cache = "";
    $stack = array();
    $auth_calc = array("+", "-", "*", "/");
    foreach(str_split($str) as $item) {
        if (in_array($item, $auth_calc)) {
            array_push($stack, $cache);
            array_push($stack, $item);
            $cache = "";
        }else if (is_numeric($item) || $item == "."){
            $cache .= $item;
        }
    }
    if ($cache != "") {
        array_push($stack, $cache);
    }
    //var_dump($stack);
    $number = new BcMathNumber($stack[0]);
    //var_dump($number);
    array_shift($stack);
    $func = "";
    foreach($stack as $item) {
        if (in_array($item, $auth_calc)) {
            $func = $item;
            continue;
        }else if($func != ""){
            switch ($func) {
                case "+":
                    $result = $number->add($item);
                    break;
                case "-":
                    $result = $number->sub($item);
                    break;
                case "*":
                    $result = $number->mul($item);
                    break;
                case "/":
                    $result = $number->div($item);
                    break;
            }
            $func = "";
        }
    }
    $return_data = explode(".", $result);
    $cache = array();
    $valid_num_find = false;
    foreach (array_reverse(str_split(end($return_data))) as $item) {
        if ($item != "0" || $valid_num_find) {
            $valid_num_find = true;
            array_push($cache, $item);
        }
    }
    $return_data[count($return_data) - 1] = join("", array_reverse($cache));
    return join(".", array_filter($return_data, function($el) {
        return $el != "";
    }));
}
/*
5
12345678991019231124+1234567890000000
12345678991019231124-1234567890000000
1-123456789123456789
123465789.123456789+987654321.987654321
1000000000-0.1
*/