import tkinter as tk
from tkinter import messagebox
import pickle
import os

# Maximum number of users allowed
MAX_USERS = 10

# User storage file
USER_FILE = 'users.pkl'

# Load users from the file
def load_users():
    if os.path.exists(USER_FILE):
        with open(USER_FILE, 'rb') as f:
            return pickle.load(f)
    return {}

# Save users to the file
def save_users(users):
    with open(USER_FILE, 'wb') as f:
        pickle.dump(users, f)

# Register a new user
def register_user():
    name = entry_name.get()
    password = entry_password.get()

    users = load_users()

    if len(users) >= MAX_USERS:
        messagebox.showerror("Error", "Maximum number of users reached!")
        return

    if name in users:
        messagebox.showerror("Error", "User already exists!")
        return

    users[name] = password
    save_users(users)

    messagebox.showinfo("Success", f"User {name} registered successfully!")
    entry_name.delete(0, tk.END)
    entry_password.delete(0, tk.END)

# Login as an existing user
def login_user():
    name = entry_name.get()
    password = entry_password.get()

    users = load_users()

    if name in users and users[name] == password:
        messagebox.showinfo("Login Successful", f"Welcome back, {name}!")
    else:
        messagebox.showerror("Login Failed", "Invalid username or password!")

    entry_name.delete(0, tk.END)
    entry_password.delete(0, tk.END)

# Setup the main window
def setup_interface():
    global entry_name, entry_password

    window = tk.Tk()
    window.title("User Interface")

    # Welcome Label
    label_welcome = tk.Label(window, text="Welcome! Please Register or Login", font=("Arial", 14))
    label_welcome.pack(pady=10)

    # Name label and entry
    label_name = tk.Label(window, text="Name")
    label_name.pack(pady=5)
    entry_name = tk.Entry(window)
    entry_name.pack(pady=5)

    # Password label and entry
    label_password = tk.Label(window, text="Password")
    label_password.pack(pady=5)
    entry_password = tk.Entry(window, show="*")
    entry_password.pack(pady=5)

    # Register button
    button_register = tk.Button(window, text="Register", command=register_user)
    button_register.pack(pady=5)

    # Login button
    button_login = tk.Button(window, text="Login", command=login_user)
    button_login.pack(pady=5)

    window.mainloop()

if __name__ == "__main__":
    setup_interface()
