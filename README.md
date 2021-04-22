# secret-santa :santa:

## Background

A fun old project from hs orchestra (i know weird place but code is written from necessity or whateva 🙃). I origanally made it in C and then wanted to make one that could run in browser so, I then made it in JS. I have uploaded it as is, and have now started to edit it slightly to meet my current standard of how I think it should be written. This project was inspired by Dr. Hannah Fry's ["Fool-Proof Secret Santa"](https://www.youtube.com/watch?v=GhnCj7Fvqt0) on Numberphile; great video you should def check it out. Anyway that's all, just a bit o' fun. If you'd like to use it yourself I'll explain below how to run each version.

## Run C version

// TODO

## Run JS version

`secret-santa` reads from a plain text file: `roster.txt` and formulates pairs of participants for the gift exchange. 
Entering your name in the input field will reveal your unique partner. If you wanna spoil the surprise 😐 
check the console for a printed list of all the partners.

The current [secret-santa](https://ahgomes.github.io/secret-santa/js/index.html) page does not allow you to change participant names without download, but you can use this link to just check it out. To run locally, you will need to use a *localhost*. Just running the `index.html` in browser will not work with reading text from `roster.txt` and will cause a **`Cross-Origin Resource Sharing Error`**[*\[Learn more\]*](https://developer.mozilla.org/en-US/docs/Web/HTTP/CORS/Errors) : 

    Cross-Origin Request Blocked: The Same Origin Policy disallows
    reading the remote resource at file:///Users/.../secret-santa/roster.txt. 
    (Reason: CORS request not http).

If you have never used a *localhost*, I'd recommend using `http-server` command-line http server. Visit www.npmjs.com/package/http-server for insallation and usage guides. 

`http-server` suggestioned options: 
  - use `-c-1` to avoid having to delete cache anytime you change `roster.txt`
  - use `-o ./path` if you changed name from `index.html` to \[path\]
