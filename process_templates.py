#!/usr/bin/env python3
import os
import jinja2
import sys
import json


def load_json_config(config_path):
    with open(config_path, "r") as config_file:
        return json.load(config_file)


def process_templates(root_dir, data):
    env_dir = root_dir
    print(f"Processing templates in {env_dir}")
    jenv = jinja2.Environment(
        loader=jinja2.FileSystemLoader(env_dir),
        # see https://ttl255.com/jinja2-tutorial-part-3-whitespace-control/
        trim_blocks=True,
        lstrip_blocks=True,
    )

    for folder, dirnames, files in os.walk(env_dir):
        # Skip hidden folders in dirnames
        dirnames[:] = [d for d in dirnames if not (d.startswith(".") and d != ".")]

        # print(f"Processing folder '{folder}'")
        for file in files:
            if file.endswith(".j2"):
                try:
                    template_full_path = os.path.join(folder, file)
                    output_full_path = template_full_path.replace(".j2", "")

                    env_rel_file_path = os.path.relpath(template_full_path, env_dir)

                    # When loading templates from the filesystem, "/" is used as the path separator, even on Windows.
                    jinja2_rel_file_path = "/".join(env_rel_file_path.split(os.sep))
                    template = jenv.get_template(jinja2_rel_file_path)

                    rendered_content = template.render(data)

                    with open(output_full_path, "w") as output_file:
                        output_file.write(rendered_content)
                    print(f"Processed {jinja2_rel_file_path}")
                except jinja2.exceptions.TemplateSyntaxError as e:
                    print(f"Template syntax error in {template_full_path}: {e}")
                    sys.exit(1)


if __name__ == "__main__":
    if len(sys.argv) > 1:
        templates_root = sys.argv[1]
    else:
        templates_root = "."
    settings = load_json_config(os.path.join(templates_root, "chip_definitions.json"))
    process_templates(templates_root, settings)
