class Game {
    constructor() {
        this.delayTime = 50;
        this.score = 0;
        this.mapFilePath = "./map.txt";
        this.roleSymbol = {
            rock: "*",
            road: " ",
            ghost: "$"
        };
        this.startAt = Date.now();
        this.KeyPress = KeyPress();
        this.Draw = Draw();
        
        kernelRegister();
    }

    kernelRegister() {
        while(true) {
           this.KeyPress.listen(); 
        }
    }

    timer() {
        
    }
    
    score(num) {
        // do Something...
    }
    
    screenRefresh() {
        setInterval(() => {
            // 更新畫面內容(負責輸出內容)
        }, 50);
    }
}

class KeyPress extends Game {
    constructor() {
        
    }
    listen() {

    }
}

class Draw extends Game{
    constructor() {
        this.map = null; // vector<map<Draw::>>
        mapProcess();
    }
    mapProcess() {
        File.open("./map.txt");
        // do something
    }
    update() {
        
    }
}

class CollectionAble extends Draw { // ghost, pacman, bullet

}

class PacMan extends CollectionAble {
    constructor() {
        
    }
    move() {
        
    }
}