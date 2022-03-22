function toFixed(d = '', length = 32, symbol = 0) {
    console.log(symbol + '0'.repeat(length - 1 - d.length) + d);
    if (d.length < length) {
        return symbol + '0'.repeat(length - 1 - d.length) + d;
    }
    return d;
}

class Binary {
//   public length: number;

    constructor({ length = 32 } = {}) {
        this.length = length;
    }

    getBinary(d) {
        return Math.abs(d).toString(2);
    }

    // 原码
    trueForm(d) {
        const two = this.getBinary(d);

        if (d >= 0) {
            return toFixed(two, this.length, 0);
        }
        return toFixed(two, this.length, 1);
    }

    // 反码
    inverse(d) {
        const trueForm = this.trueForm(d);
        if (d >= 0) {
            return trueForm;
        }
        let data = '';
        // eslint-disable-next-line no-plusplus
        for (let index = 0; index < this.length; index++) {
            const item = trueForm[index];
            if (index === 0) {
                data += item;
            } else {
                data += Math.abs(+item - 1);
            }
        }
        return data;
    }

    // 补码
    complement(d) {
        const trueForm = this.trueForm(d);
        const inverse = this.inverse(d);
        if (d >= 0) {
            return trueForm;
        }
        const valid = inverse.slice(1);
        console.log("valid", typeof valid, valid);
        const validTenComplete = parseInt(valid, 2) + 1;
        const validTwoComplete = toFixed(
            validTenComplete.toString(2),
            this.length,
            1
        );
        console.log("validTenComplete", typeof validTenComplete, validTenComplete);
        console.log("validTwoComplete", typeof validTwoComplete, validTwoComplete);
        return validTwoComplete;
    }
}
