import tkinter as tk
from tkinter import ttk

class WebsiteApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Website App")

        # Navigation Bar
        navbar = tk.Frame(root, bg='blue', padx=10, pady=5)
        navbar.pack(side='top', fill='x')

        website_label = tk.Label(navbar, text="dhami", font=('Arial', 16), bg='pink', fg='white')
        website_label.grid(row=0, column=0, padx=10, pady=5)

        sections = ['Home', 'Payment', 'Login']
        for idx, section in enumerate(sections):
            section_btn = tk.Button(navbar, text=section)
            section_btn.grid(row=0, column=idx + 1, padx=10, pady=5)

        # Carousel Rectangle Box
        carousel_frame = tk.Frame(root, bg='lightgray', padx=20, pady=20)
        carousel_frame.pack(pady=20)

        carousel_label = tk.Label(carousel_frame, text="Carousel Box", font=('Arial', 14))
        carousel_label.pack()

        # Small Squares with Input Text
        input_frame = tk.Frame(root, pady=10,bg='black',height=100)
        input_frame.pack()

        for i in range(3):
            square_label = tk.Label(input_frame, text=f"Square {i+1}", font=('Arial', 12))
            square_label.grid(row=0, column=i, padx=20)

        # Footer
        footer = tk.Frame(root, bg='gray', padx=10, pady=5)
        footer.pack(side='bottom', fill='x')

        footer_label = tk.Label(footer, text="© 2023 Your Website. All rights reserved.", font=('Arial', 10), fg='white', bg='gray')
        footer_label.pack()


if __name__ == "__main__":
    root = tk.Tk()
    app = WebsiteApp(root)
    root.geometry("600x400")
    root.mainloop()
