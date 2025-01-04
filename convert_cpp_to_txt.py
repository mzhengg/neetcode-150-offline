import os
import re

# Create the output directory if it doesn't exist
output_dir = "output"
os.makedirs(output_dir, exist_ok=True)

# Function to extract the number prefix from a folder name
def extract_number_prefix(folder_name):
    match = re.match(r'(\d+)', folder_name)
    return int(match.group(1)) if match else float('inf')

# Collect all top-level folders and sort them in descending order based on the number prefix
folders = [root for root, dirs, files in os.walk('.') if root != '.' and os.path.dirname(root) == '.']
folders.sort(key=lambda folder: extract_number_prefix(os.path.basename(folder)), reverse=True)

# Loop through each sorted folder
for folder in folders:
    output_file = os.path.join(output_dir, f"{os.path.basename(folder)}.txt")
    
    # Open the temporary file in write mode
    with open(output_file, 'w') as outfile:
        for root, dirs, files in os.walk(folder):
            for file in files:
                if file.endswith('.cpp'):
                    file_path = os.path.join(root, file)
                    # Get the relative path of the folder
                    relative_path = os.path.relpath(root, '.')
                    # Read the content of each .cpp file and write it to the temp file
                    with open(file_path, 'r') as infile:
                        lines = infile.readlines()
                        # Filter out lines containing '/*' or '*/'
                        filtered_lines = [line for line in lines if '/*' not in line and '*/' not in line]
                        # Write the filtered content to the temp file
                        outfile.writelines(filtered_lines)
                        outfile.write("\n\n")  # Add some space between files

print("All .cpp files have been concatenated into individual .txt files for each top-level folder in the 'output' directory.")