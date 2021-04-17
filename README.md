# secret-santa :santa:


## Run

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





