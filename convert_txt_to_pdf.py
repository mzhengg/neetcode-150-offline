import os
from fpdf import FPDF

pdf = FPDF()
pdf.set_auto_page_break(auto=True, margin=15)

# Add a Unicode font (DejaVu)
pdf.add_font('DejaVu', '', 'DejaVuSansCondensed.ttf', uni=True)
pdf.add_font('DejaVu', 'B', 'DejaVuSansCondensed-Bold.ttf', uni=True)

# Directory containing text files
directory = 'output/'

# Strings to bolden
bolden_strings = ["Problem:", "Description", "Intuition:", "Approach", "Time Complexity", "Space Complexity"]

# Add a title page with "Neetcode 150"
pdf.add_page()
pdf.set_font("DejaVu", 'B', size=36)
pdf.cell(0, 100, '', ln=True)  # Move to the center of the page
pdf.cell(0, 10, "Neetcode 150 Offline", ln=True, align='C')

# Get the list of text files and sort them in descending order by the number prefix
filenames = sorted(
    [f for f in os.listdir(directory) if f.endswith('.txt')],
    key=lambda x: int(x.split('_')[0]),
    reverse=False
)

# Loop through each text file in the sorted list
for filename in filenames:
    filepath = os.path.join(directory, filename)
    
    # Add a title page for each file
    pdf.add_page()
    pdf.set_font("DejaVu", 'B', size=24)
    pdf.cell(0, 100, '', ln=True)  # Move to the center of the page
    pdf.cell(0, 10, filename.replace(".txt", "").replace("_", ") ", 1).replace("_", " "), ln=True, align='C')
    
    # Add a new page for the content
    pdf.add_page()
    pdf.set_font("DejaVu", size=8)
    
    with open(filepath, 'r', encoding='utf-8') as file:
        for line in file:
            # Check if the line contains any of the specified strings
            if any(bolden_string in line for bolden_string in bolden_strings):
                pdf.set_font("DejaVu", 'B', size=8)
            else:
                pdf.set_font("DejaVu", size=8)
            
            # Measure the width of the text
            text_width = pdf.get_string_width(line)
            page_width = pdf.w - 2 * pdf.l_margin
            
            if text_width > page_width:
                pdf.multi_cell(0, 4, line)
            else:
                pdf.cell(0, 4, line, ln=True)
            
# Save the PDF
pdf.output("Neetcode_150_Offline.pdf")