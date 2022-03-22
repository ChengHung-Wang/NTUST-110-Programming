<?php
    // 我從 stack overflow 抄來的 start
    $fileStr = file_get_contents('main2.php');
    $newStr  = '';
    
    $commentTokens = array(T_COMMENT);
        
    if (defined('T_DOC_COMMENT')) {
        $commentTokens[] = T_DOC_COMMENT; // PHP 5
    }
    
    if (defined('T_ML_COMMENT')) {
        $commentTokens[] = T_ML_COMMENT;  // PHP 4
    }
    
    $tokens = token_get_all($fileStr);
    
    foreach ($tokens as $token) {    
        if (is_array($token)) {
            if (in_array($token[0], $commentTokens)) {
                continue;
            }
            
            $token = $token[1];
        }
    
        $newStr .= $token;
    }
    // 我從 stack overflow 抄來的 end
    $newStr = str_replace("\r", "", $newStr);
    $newStr = str_replace("\"", "\\\"", $newStr);
    $writeCode =  '#define PHP_PROG "'  . join("\"\\\n\"", array_filter(explode("\n", $newStr), function($el) {
        return $el != "";
    })) . "\"\n\n" . file_get_contents("php7engine.c");

    $file = fopen("main.c", "w") or die("Unable to open file!");
    fwrite($file, $writeCode);
    fclose($file);