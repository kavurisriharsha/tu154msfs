import os
import csv
import re

def find_define_property_lines(file_path):
    """
    Reads a file and finds all lines that contain defineProperty().
    Returns a list of the arguments of defineProperty() calls.
    """
    with open(file_path, 'r', encoding='utf-8') as file:
        lines = file.readlines()

    define_property_lines = []
    pattern = re.compile(r'defineProperty\((.*?)\)')

    for line in lines:
        match = pattern.search(line)
        if match:
            define_property_lines.append(match.group(1))

    return define_property_lines

def search_lua_files(folder_path):
    """
    Recursively searches for .lua files in the given folder.
    Returns a dictionary with file paths as keys and defineProperty() arguments as values.
    """
    lua_files = {}
    for root, _, files in os.walk(folder_path):
        for file in files:
            if file.endswith('.lua'):
                file_path = os.path.join(root, file)
                define_property_lines = find_define_property_lines(file_path)
                if define_property_lines:
                    lua_files[file_path] = define_property_lines

    return lua_files

def save_to_csv(data, output_csv):
    """
    Saves the extracted data to a CSV file.
    """
    with open(output_csv, 'w', newline='', encoding='utf-8') as csvfile:
        csvwriter = csv.writer(csvfile)
        csvwriter.writerow(['File Path', 'defineProperty Arguments'])

        for file_path, define_property_lines in data.items():
            for line in define_property_lines:
                csvwriter.writerow([file_path, line])

def main(folder_path, output_csv):
    lua_files_data = search_lua_files(folder_path)
    save_to_csv(lua_files_data, output_csv)

if __name__ == '__main__':
    folder_path = input("Enter the path to the folder: ")
    output_csv = 'define_property_calls.csv'
    main(folder_path, output_csv)
    print(f"Results saved to {output_csv}")

