<?php
foreach (explode("\n", preg_replace('!/\*.*?\*/!s', '', file_get_contents("./main2.php"))) as $line) {
    echo sprintf("\"%s\"\\\n", str_replace("\"", "\\\"", $line));
}
echo "\"\"";
