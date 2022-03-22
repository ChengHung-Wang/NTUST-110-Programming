function convert(data = "") {
    let result = "";
    let authCalc = ["+", "-", "*", "/", "÷"];
    let stack = [];
    // console.log(data.split(""));
    data.split("").forEach((value) => {
        if (authCalc.indexOf(value) != -1 && stack[stack.length - 1] != "(") {
            if (!(value == "*" || value == "/" || value == "÷")) {
                result += stack.filter(e => e != "(").reverse().join("");
                // +*-
                // -*+
                stack = [];
            }
        }
        if (authCalc.indexOf(value) != -1 || value == "(") {
            stack.push(value);
        }
        if (value >= 0 && value <= 9) {
            result += value;
        }
        if (value == ")") {
            result += stack.filter(e => e != "(").reverse().join("");
            stack = [];
        }
    })
    result += stack.filter(e => e != "(").reverse().join("");
    return result;
}