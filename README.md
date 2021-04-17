# secret-santa :santa:

## Background

A fun old project from hs orchestra (i know weird place but code is written from necessity or whateva 🙃). I origanally made it in C and then wanted to make one that could run in browser so, I then made it in JS. I have uploaded it as is, and have now started to edit it slightly to meet my current standard of how I think it should be written. This project was inspired by Dr. Hannah Fry's ["Fool-Proof Secret Santa"](https://www.youtube.com/watch?v=GhnCj7Fvqt0) on Numberphile; great video you should def check it out. Anyway that's all, just a bit o' fun. If you'd like to use it yourself I'll explain below how to run each version.

## Run C version

// TODO

## Run JS version

`secret-santa` reads from a JSON file: `roster.json` and formulates pairs of `participants` for the gift exchange. 
Entering your name in the input field will reveal your unique partner. If you wanna spoil the surprise 😐 
check the console for a printed list of all the partners.

<table>
  <td>

The current [secret-santa](https://ahgomes.github.io/secret-santa/) page does not allow you to change `participants` names without download, but you can use this link to just check it out. To run locally, you will need to use a *localhost*. Just running the `index.html` in browser will not work with reading text from `roster.json` and will cause a **`Cross-Origin Resource Sharing Error`**[*\[Learn more\]*](https://developer.mozilla.org/en-US/docs/Web/HTTP/CORS/Errors) : 

    Cross-Origin Request Blocked: The Same Origin Policy disallows
    reading the remote resource at file:///Users/.../secret-santa/roster.json. 
    (Reason: CORS request not http).

If you have never used a *localhost*, I'd recommend using `http-server` command-line http server. Visit www.npmjs.com/package/http-server for insallation and usage guides. 

`http-server` suggestioned options: 
  - use `-c-1` to avoid having to delete cash anytime you change `roster.json`
  - use `-o ./path` if you changed name from `index.html` to \[path\]

  </td>
</table>

```diff
+ tl;dr : download & use localhost
```

### Formatting JSON File

A template JSON file is included in the repository. Make sure to keep the same/proper JSON format. 

<!--<table>
 <tr>
  <th colspan="2">
      
   Must use keyword `participants`
  </th>
 </tr>
 <tr>
  <td>✘ bad</td>
  <td>✔︎ good</td>
 </tr>
 <tr> 
  <td> 
       
  ```json
  { "people" : [
    "Alice",
    "Bob"
  ]}
  ```
  </td>
  <td>
  
  ```json
  { "participants" : [
      "Alice",
      "Bob"
  ]}
  ```    
  </td> 
 </tr>
</table>
-->



<table>
 <tr>
  <th colspan="2">
      
   Must use keyword `participants`
  </th>
 </tr>
 <tr>
  <td>✘ bad</td>
  <td>✔︎ good</td>
 </tr>
 <tr> 
  <td> 
       
  ```json
  { "people" : [
    "Alice",
    "Bob"
  ]}
  ```
  </td>
  <td>
  
  ```json
  { "participants" : [
      "Alice",
      "Bob"
  ]}
  ```    
  </td> 
 </tr>
</table>

// TODO: finish formatting examples



