let names;
let snames;
let printed = false;
let type_count = 0;

window.onload = main;

async function main() {
    await getRoster();
    select();
    printList();
}

async function getRoster(path = 'roster.txt') {
    const result = await fetch(path, {
        cache: 'no-cache',
    }).then(response => response.text())
    .catch(error => console.log(error));
    names = result.trim().split(/[\r\n]+/gm);
}

function Random() {
    this.seed = (new Date).getTime();

    this.srand = function(seed) {
        this.seed = seed;
    }

    this.rand = function() {
        let munipulated_seed = this.seed;
        let seed_length = this.seed.toString().length;
        let result = 0;
        do {
            munipulated_seed *= munipulated_seed;
            let temp = munipulated_seed.toString();
            temp = temp.substr((temp.length - seed_length) / 2, seed_length)
            munipulated_seed = parseInt(temp);
            result += temp;
        } while (result.length < 20);
        this.seed = munipulated_seed;
        return parseInt(result) / Math.pow(10, result.length - 1);
    }
}

function select(seed = 2) {
    let rand_object = new Random();
    rand_object.srand(seed);
    let rand_num = Math.floor(rand_object.rand() * names.length);
    let iterations = Math.floor(rand_object.rand() * 100)
    for (let i = 0; i < iterations; i++) {
        let temp = names[i % names.length];
        names[i % names.length] = names[rand_num];
        names[rand_num] = temp;
        rand_num = Math.floor(rand_object.rand() * names.length);
    }

    snames = [];
    for (let i = 1; i < names.length; i++)
        snames.push(names[i]);
    snames.push(names[0]);
}

function enter(e) {
    if (printed) clear();
    let input = document.querySelector('input')
    if (e.keyCode == 13 || e.which == 13) {
        if (input.value == '' || type_count == 0) clear();
        else print(input.value);
        type_count = 0;
    } else type_count++;
}

function print(value) {
    let print_area = document.querySelector('printarea');
    for (let i = 0; i < names.length; i++) {
        if (value == names[i]) {
            print_area.innerHTML = snames[i] + '<br/><span style="color: #000">[PRESS ENTER]</span>';
            document.querySelector('.face').innerHTML = 'sentiment_very_satisfied';
            printed = true;
            return;
        }
    }
    print_area.innerHTML = ('<span style="color: #f00; ">YOU ARE NOT <br/> ON THE LIST</span>');
    document.querySelector('.face').innerHTML = 'sentiment_dissatisfied';
}

function printList() {
    let pnames = [];
    for (let i = 0; i < names.length; i++)
        pnames.push(names[i] + ' --> ' + snames[i]);
    pnames.sort(function(a, b) {
        if (a.split(" ")[1]  == b.split(" ")[1]) return a.split(" ")[0] > b.split(" ")[0]
        return a.split(" ")[1] > b.split(" ")[1];
    });
    for (let i = 0; i < pnames.length; i++)
        console.log(pnames[i]);
}

function clear() {
    document.querySelector('input').value = '';
    document.querySelector('printarea').innerHTML = 'Receiving Gift';
    document.querySelector('.face').innerHTML = 'radio_button_unchecked';
    printed = false;
    return;
}
