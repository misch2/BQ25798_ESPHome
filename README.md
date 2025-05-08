# BQ25798 component for ESPHome



## Development

After any change to Jinja2 templates (.j2 files), run the following command to generate the real files:
```bash
python3 process_templates.py
```

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