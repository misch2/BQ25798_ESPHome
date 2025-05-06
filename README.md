# BQ25798 component for ESPHome



## Development

Best combined with the [Run on Save](https://marketplace.visualstudio.com/items?itemName=emeraldwalk.runonsave) extension set to this:

```json
"emeraldwalk.runonsave": {
    "commands": [
        {
            "match": "\\.j2$",
            "cmd": "python ${workspaceFolder}/process_templates.py ${workspaceFolder}",
            "message": "Running ${fileBasenameNoExtension}...",
        }
    ]
}
```